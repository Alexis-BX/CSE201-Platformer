#ifndef LEVEL_LOAD_H
#define LEVEL_LOAD_H


class Level_load
{

public:

    Level_load();

    void read_level_image(const char* filename);

    void color_to_object(int B, int G, int R, int x, int y);
};

#endif // LEVEL_LOAD_H