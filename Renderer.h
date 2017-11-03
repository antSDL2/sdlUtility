//Renderer.h
#ifndef NEO_TOOLBOX_RENDERER_H
#define NEO_TOOLBOX_RENDERER_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <gl/gl.h>

namespace AtUtility {
    namespace Renderer {
        void Clear();
        SDL_Cursor *CreateCursorFromData(Uint8 *Pixels, int Width, int Height);
        void GetStringSize(std::string FontPath, int Size, std::string Text, int &Width, int &Height);
        int GetViewportHeight();
        int GetViewportWidth();
        SDL_Surface *LoadImage(std::string Location);
        void RenderDisk(float TargetX, float TargetY, float OuterRadius, float InnerRadius, float Angle = 0, bool Filled = true);
        void RenderRectangle(float TargetX, float TargetY, float Width, float Height, bool Filled = true);
        void RenderTriangle(float TargetX, float TargetY, float Width, float Height);
        void Reset(GLenum Mode);
        void Rotate(GLenum Mode, float Angle, float CenterX, float CenterY);
        void Scale(GLenum Mode, float ScaleX, float ScaleY, float CenterX, float CenterY);
        bool SaveScreenshot(std::string Location);
        void SetClearColor(float R, float G, float B, float A = 0);
        void SetClearColor(int R, int G, int B, int A = 0);
        void SetColor(float R, float G, float B, float A = 1);
        void SetColor(int R, int G, int B, int A = 255);
        void Setup2D(int Width, int Height);
        void Setup3D(int Width, int Height);
        void SetViewport(int Width, int Height);
        void Who();
    }
}

#endif
