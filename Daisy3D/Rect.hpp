class Rect{
    public:
        int x,y,width,height;
        SDL_Rect rect;
        Rect(int rectX,int rectY,int rectW,int rectH){
            x = rectX;
            y = rectY;
            width = rectW;
            height = rectH;
            rect.x = x;
            rect.y = y;
            rect.w = width;
            rect.h = height;
        }
        SDL_Rect ReturnSdlRect(){
            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            rect.w = width;
            rect.h = height;

            return rect;
        }
        /*
        static void Draw(Rect rect,Color color){
            rect.rect.x = rect.x;
            rect.rect.y = rect.y;
            rect.rect.w = rect.width;
            rect.rect.h = rect.height;
            SDL_SetRenderDrawColor(Poppy::renderer,color.red,color.green,color.blue,color.alpha);
            //SDL_SetAlpha();
            SDL_RenderFillRects(Poppy::renderer,&rect.rect,1);
        }
        */
        
};