#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Funcion para convertir a gris
unsigned char grayscale(unsigned char r, unsigned char g, unsigned char b)
{
    return (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Uso: %s <imagen_entrada.jpg>\n", argv[1]);
        return 1;
    }

    int width, height, channels;
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 0);

    if (!img)
    {
        printf("No se pudo cargar la imagen: %s\n", argv[1]);
        printf("Razon: %s\n", stbi_failure_reason());
        return 1;
    }

    unsigned char *gray_img = (unsigned char *)malloc(width * height);
    if (!gray_img)
    {
        printf("No se pudo asignar memoria.\n");
        stbi_image_free(img);
        return 1;
    }

    for (int i = 0; i < width * height; i++)
    {
        unsigned char r = img[i * channels + 0];
        unsigned char g = img[i * channels + 1];
        unsigned char b = img[i * channels + 2];
        gray_img[i] = grayscale(r, g, b);
    }

    if (!stbi_write_jpg("casaR_grayscale.jpg", width, height, 1, gray_img, 100))
    {
        printf("Error al guardar la imagen.\n");
    }
    else
    {
        printf("Imagen convertida guardada como output_grayscale.jpg\n");
    }

    free(gray_img);
    stbi_image_free(img);
    return 0;
}
