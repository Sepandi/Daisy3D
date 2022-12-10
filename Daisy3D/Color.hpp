class Color{
    public:
        SDL_Color sdlColor;
        int red,green,blue,alpha;
        Color(Uint8 r,Uint8 g,Uint8 b,Uint8 a){
            sdlColor = {r,g,b,a};
            red = r;
            green = g;
            blue = b;
            alpha = a;
        }
};