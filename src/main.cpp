
#include <includes.h>
#include <windowing/Window.h>
#include <windowing/gui.h>


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//timing fps
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void custom_keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(Window* window);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


int main()
{
	Window window(SCR_WIDTH, SCR_HEIGHT);

    window.setMouseCallback(mouse_callback);
    window.setScrollCallback(scroll_callback);
    window.setKeyboardCallback(custom_keyboard_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // Render Loop
    // ----------------------------------------------
    while (!window.shouldClose())
    {
        //pre frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;


        processInput(&window);

        // Render
        // -----------------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Imgui related window stuff;
        window.imgui_window->NewFrame();
        window.imgui_window->Update();
        window.imgui_window->Render();
    
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window.glfw_window);
        glfwPollEvents();

    }

    
    // glfw: terminate, clearing all previously allocated GLFW resources.
     //------------------------------------------------------------------
    glfwTerminate();
    return 0;

}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(Window * myWindowType)
{
    ImGuiIO& io = ImGui::GetIO();

    if (io.WantCaptureKeyboard)
    {
        return;
    }

    if (myWindowType->pressedKey(GLFW_KEY_ESCAPE))
        myWindowType->close();
}

void custom_keyboard_callback(GLFWwindow * window, int key, int scancode, int action, int mods) {

    if (key == GLFW_KEY_LEFT_ALT && action == GLFW_PRESS) {
        Window* myWindowType = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        myWindowType->captureMouseInput = !myWindowType->captureMouseInput;
        myWindowType->imgui_window->show_main_window = !myWindowType->imgui_window->show_main_window;
        if (myWindowType->captureMouseInput)
        {
            myWindowType->captureAndHideCursor();
        }
        else {
            myWindowType->stopHidingCursor();
        }
    }

    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
}

void mouse_callback(GLFWwindow * window, double xposIn, double yposIn) {

    ImGuiIO& io = ImGui::GetIO();

    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    Window* myWindowType = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

    if (myWindowType->firstMouse)
    {
        myWindowType->lastX = xpos;
        myWindowType->lastY = ypos;
        myWindowType->firstMouse = false;
    }

    float xoffset = xpos - myWindowType->lastX;
    float yoffset = myWindowType->lastY - ypos; // reversed since y-coordinates go from bottom to top

    myWindowType->lastX = xpos;
    myWindowType->lastY = ypos;

    if (!io.WantCaptureMouse && myWindowType->captureMouseInput)
    {
        //do application things
   }

    ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
    ImGuiIO& io = ImGui::GetIO();

    if (!io.WantCaptureMouse)
    {
        //do application things
    }

    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);

}