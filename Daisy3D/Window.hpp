namespace Daisy{
    // Some variables
    bool shouldForceQuit = false;
    SDL_Window *window = NULL;
    SDL_GLContext context = NULL;
    int width,height;
    bool firstLoop = true;
    // Events
    SDL_Event events;

    // DeltaTime Things
    Uint64 TimeNow,TimeAtLast;
    double deltaTime = 0;
    float passedSeconds = 0;
    float fps = 0;

    // System Info
    std::string platform = "";
    

    // Initializes a New Window
    void WindowInit(std::string name,int w,int h){
        // Check if sdl is initialized 
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            Utils::Error("SDL could not be initialized");
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

        window = SDL_CreateWindow(name.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOWEVENT_SIZE_CHANGED);
        context = SDL_GL_CreateContext(window);

        gladLoadGLLoader(SDL_GL_GetProcAddress);
        std::cout << "\033[43m\033[1;31m[  Manufacturer  ]\033[0m\033[1;31m   "<< glGetString(GL_VENDOR) << " \033[0m" << std::endl;
        std::cout << "\033[43m\033[1;31m[    GPU Model   ]\033[0m\033[1;31m   "<< glGetString(GL_RENDERER) << " \033[0m" << std::endl;
        std::cout << "\033[43m\033[1;31m[ OpenGL Version ]\033[0m\033[1;31m   "<< glGetString(GL_VERSION) << " \033[0m" << std::endl;

        width = w;
        height = h;

        

    }
    void ForceQuit(){
        #ifdef __APPLE__
            system("osascript -e \'tell application (path to frontmost application as text) to display dialog \"GAME CRASHED\" buttons {\"OK\"} with icon stop\'");
            Utils::Error("Crashed");
        #else
            Utils::Error("Crashed");
        #endif
        shouldForceQuit = true;
    } 


    // Checks if window should be open
    bool WindowShouldBeOpen(int r,int g,int b){
        
        // Gets Window Events
        while (SDL_PollEvent(&events)){
            if (events.type == SDL_QUIT || shouldForceQuit){
                return false;
            }
            if (events.type == SDL_WINDOWEVENT_RESIZED){
                SDL_GetWindowSize(window,&width,&height);
                std::cout << "hi";
            }
            
            
        }
        SDL_PumpEvents();
        Keys::isDown = SDL_GetKeyboardState(NULL);

        TimeAtLast = TimeNow;
        TimeNow = SDL_GetPerformanceCounter();

        deltaTime = (double)((TimeNow - TimeAtLast) / (double)SDL_GetPerformanceFrequency() );
        passedSeconds += deltaTime;
        if (firstLoop){
            passedSeconds = 0;
            firstLoop = false;
        }

        

        return true;
    }  

    void Quit(){
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(0);
    } 
}