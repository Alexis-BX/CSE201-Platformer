#include "listheaders.h"
#include "test.h"
#include "music.h"
#include <QSound>

View* view;

Texture* gtexture;

Collision_master* collision_master;

int main(int argc, char *argv[])
{

    QApplication application(argc, argv);

    collision_master = new Collision_master();

    gtexture = new Texture();

    view = new View(pair{793,505});

    //view->play_level(view->current_level);
    view->open_menu();

    view->show();

    return application.exec();

}


