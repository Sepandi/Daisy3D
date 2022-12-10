namespace Utils{
    template <typename anyType>
    void Info(anyType object){
        #ifdef __APPLE__
            std::cout << "\033[0;106m\033[36m[INFO]\033[0m\033[36m [ " << object << " ]\033[0m" << std::endl; 
        #else
            std::cout << "[INFO] [ " << object << " ]" << std::endl; 
        #endif
        
        
    }
    template <typename anyType>
    void Error(anyType object) {
        #ifdef __APPLE__
            cout << "\033[43m\033[1;31m[ERROR]\033[0m\033[1;31m [ " << object << " ]\033[0m" << std::endl; 
        #else
            cout << "[ERROR] [ " << object << " ]" << std::endl; 
        #endif
    }

    inline bool FileExists(const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
            fclose(file);
            return true;
        } else {
            return false;
        }   
    }
}