#include "listheaders.h"

View::View(pair screen_size, int block_size, QWidget* parent) :
    QGraphicsView(parent), block_size(block_size), screen_size(screen_size)
{
    //scene set up
    setScene(new QGraphicsScene());

    // load and create level
    level_load = new Level_load(this);
    level_load->load_level(":/Images/Levels/Level_agathe_001.png");
}

void View::update_background()
{
    for(unsigned long long i = 0 ; i < backgrounds.size(); i++)
    {
        backgrounds[i]->setX(backgrounds[i]->x()-player->speed.x/backgrounds[i]->speed_ratio);
    }
}

/** OLD VERSION THAT ONLY WORKED ON WINDOWS USE QT TOOLS TO MAKE IT WORK FOR EVERYTHING
    std::ifstream image;

    image.open(filename);

    if(!image.is_open())
    {
        printf("not open");
    }

    int height = 0,width = 0;

    for(int i = 0 ; i < 54 ; i++)
    {
        if(i == 18)
        {
            width = image.get();
        }
        else if(i == 22)
        {
            height = image.get();
        }
        else
        {
            image.get();
        }
    }

    world_size.bottom = 0;
    world_size.left = 0;
    world_size.top = - block_size * height;
    world_size.right = block_size * width;
    //std::cout << width << "  " << height << std::endl;



    Now data should contain the (R, G, B) values of the pixels. The color of pixel (i, j) is stored at
    data[3 * (i * width + j)], data[3 * (i * width + j) + 1] and data[3 * (i * width + j) + 2].




while(image.good())
{
    R = image.get();
    G = image.get();
    B = image.get();
    std::cout << R << "   " << G << "   " << B << "   " << std::endl;

}


image >> buffer;

while(image.good())
{
    std::cout << buffer << std::endl;
    image >> buffer;
}

int info[200];
FILE* f = fopen(filename, "rb");


for(int i = 0; i < 100; i ++)
{
    for(int j = 0; j < 100; j++)
    {
        info = std::f

        std::cout << *info << std::endl;
    }
}


fread(info, sizeof(unsigned char), 3, f);

std::ifstream image;
image.open(filename);

char* buffer = new char [50];

if(!image.is_open())
{
    printf("not open");
}



image.seekg (0, image.end);
int length = image.tellg();
image.seekg (0, image.beg);
printf("3");

printf("4");
std::cout << "Reading " << length << " characters... ";
read data as a block:
image.read (buffer,length);
printf("5");
FILE* f = fopen(filename, "rb");
printf("2");
unsigned char info[54];
printf("3");
fread(info, sizeof(unsigned char), 54, image); // read the 54-byte header
printf("4");

extract image height and width from header
int width = *(int*)&info[18];
int height = *(int*)&info[22];
std::cout << width << std::endl;
std::cout << height << std::endl;

const std::size_t size = 3 * width * height;
std::cout << "width" << std::endl;
unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
std::cout << "width" << std::endl;
fread(data, sizeof(int), size, f); // read the rest of the data at once
fclose(f);

printf("5");


if (ord==1){
 if ord==1 means you are using a windows
the swap between every first and third pixel is done because windows stores the
color values as (B, G, R) triples, not (R, G, B).

for(i = 0; i < size; i += 3){
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
}}




for(int i = 0; i < height; i ++)
{
    for(int j = 0; j < width; j++)
    {
         int value [3];
         value[0] = data[3 * (i * width + j)];
         value [1]=data[3 * (i * width + j)+1];
         value [2]= data[3 * (i * width + j)+2];
         convert (value[0],value[1], value [2],i,j);  //this function creates ther object at position (i,j)
    }
}
printf("3");

int diff=4;

if (v0<=diff && v1<=diff && v2<=diff)
{
    //CREATE PERMANEMT BLOCK at position (i,j)
    Block_type btype = permanent;
    Block_texture btexture = brick;
    Block_state bstate = initial;
    create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
}
else if (v0>=255-diff && v1>=255-diff && v2>=255-diff)
{
    //CREATE nothing at position (i,j)
}
else if (36-diff<=v0 && v0<=36+diff  && 28-diff<=v1 && v1<=28+diff && 237-diff<=v2 && v2<=237+diff)
{
    //CREATE enemy stating point at position (i,j)
}
else if (87-diff<=v0 && v0<=87+diff  && 122-diff<=v1 && v1<=122+diff && 185-diff<=v2 && v2<=185+diff)
{
    //CREATE ground  at position (i,j)
    Block_type btype = permanent;
    Block_texture btexture = dirt;
    Block_state bstate = initial;
    create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
}
else if (76-diff<=v0 && v0<=76+diff  && 177-diff<=v1 && v1<=177+diff && 34-diff<=v2 && v2<=34+diff)
{
    //CREATE grass  at position (i,j)
    this->scene->addItem(new Special_block_above(pair{greal(i*block_size),greal(-18-j*block_size)}));


    Block_type btype = permanent;
    Block_texture btexture = grass;
    Block_state bstate = initial;
    create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
}
else if ( v0<=0+diff  && 242-diff<=v1 && v1<=242+diff && 255-diff<=v2)
{
    //CREATE coin at position (i,j)
    Block_type btype = permanent;
    Block_texture btexture = grass;
    Block_state bstate = initial;
    create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
}
else if (204-diff<=v0 && v0<=204+diff  && 72-diff<=v1 && v1<=72+diff && 63-diff<=v2 && v2<=63+diff)
{
    //CREATE ?/active block  at position (i,j)
    Block_type btype = active;
    Block_texture btexture = question_mark;
    Block_state bstate = operative;
    create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
}
else if (39-diff<=v0 && v0<=39+diff  && 127-diff<=v1 && v1<=127+diff && 255-diff<=v2)
{
    //CREATE breakable block  at position (i,j)
    Block_type btype = breakable;
    Block_texture btexture = crate;
    Block_state bstate = initial;
    create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
}
**/





