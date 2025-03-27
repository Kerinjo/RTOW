#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned bounded_rand(unsigned range)
{
    for (unsigned x, r;;)
        if (x = rand(), r = x % range, x - r <= -range)
            return r;
}

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    std::srand(std::time({}));
    
    for (int j = 0; j < image_height; j++)
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++)
        {
            // get random value on [1, 255]
            unsigned random = 1 + bounded_rand(255);
            unsigned more_intense_random = 86 + bounded_rand(170);

            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            // Make every even blue also random... but more intense?
            if (j > 85 & j < 127 & (i + j) % 3 == 0) {
                r = double(random) / (image_width - 1);
                b = double(more_intense_random) / (image_width-1);
            }

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
