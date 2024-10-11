//
// Created by erdem on 26.07.2024.
//

#ifndef CRIMSON_TEXTURE_H
#define CRIMSON_TEXTURE_H

#include <iostream>
#include <GL/gl.h>
#include <SOIL2/SOIL2.h>
#include "stb_image.h"

using namespace std;

namespace Crimson
{
    class Texture {
    public:
        Texture();
        ~Texture();

        void SetFilename(const char* filename)
        {
            this->filename = filename;
        }
        string GetFilename()
        {
            return filename;
        }
        GLuint GetTextureID();
        bool TextureExists();
        void UseTexture(int textureOrder);
        void LoadTexture(const char* filename);
        void LoadTexture();
    private:
        int width, height, bitDepth;
        GLuint textureId;
        string filename;
    };
}

#endif //CRIMSON_TEXTURE_H
