/**
 * Copies a BMP piece by piece, just because.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

void update_headers(BITMAPINFOHEADER *bi, BITMAPFILEHEADER *bf, float scale)
{
    bi -> biWidth *= scale;
    bi -> biHeight *= scale;

    bf -> bfSize -= bi -> biSizeImage;
    int padding = (4 - ((bi -> biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;
    bi -> biSizeImage = ((bi -> biWidth * sizeof(RGBTRIPLE)) + padding) * abs(bi -> biHeight);
    bf -> bfSize += bi -> biSizeImage;
}

void write_line(RGBTRIPLE *buf, int count, FILE *outptr, int padding)
{
    fwrite(buf, sizeof(RGBTRIPLE), count, outptr);
    // Add padding to outpt
    for (int i = 0; i < padding; i++)
    {
        fputc(0x00, outptr);
    }
}

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    int scale = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int iHeight = abs(bi.biHeight);
    int iWidth = bi.biWidth;
    int iPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    update_headers(&bi, &bf, scale);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    RGBTRIPLE *buf = malloc(sizeof(RGBTRIPLE) * bi.biWidth);
    if (buf == NULL)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Buffer allocation failed.\n");
        return 5;
    }

    // iterate over infile's scanlines
    for (int row = 0; row < iHeight; row++)
    {
        // iterate over pixels in scanline
        for (int px = 0; px < iWidth; px++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            for (int i = 0; i < scale; i++)
            {
                buf[(px * scale) + i] = triple;
            }
        }
        // skip over padding, if any
        fseek(inptr, iPadding, SEEK_CUR);

        for (int i = 0; i < scale; i++)
        {
            write_line(buf, bi.biWidth, outptr, padding);
        }
    }

    free(buf);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}