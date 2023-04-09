

int rgbToInt(int r, int g, int b) {
    int color = (r << 16) + (g << 8) + b;
    return color;
}

int main()
{
    printf("%d", rgbToInt(1, 1, 1));
}