#include "collectable.h"
#include "player.h"
#include "view.h"
#include "global.h"


Collectable::Collectable(pair position, int creator_object_size_y, pair size, QGraphicsItem* parent):  // constructor: gives default aspects of the collectable
      QObject (), QGraphicsPixmapItem (parent)
{
    qDebug() << position.x << position.y;

    setPos(position.x, position.y);

    this -> size = size;     // gives the size of the collectable

    create_collision_range();

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);

}

void Collectable::create_collision_range() //create the collision box in order to do the collisions
{
    collision_range = new QGraphicsRectItem(this);

    collision_range -> setRect(0,0,size.x + size.x/2, size.y + size.y/2);

    collision_range -> setPos(0 - size.x/4, 0 -size.y/4);

    collision_range->setOpacity(0);
}

// collision function
bool Collectable::collision_right()
{
    // return if the right of the collectable suffers a collision with the player
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            if (speed.x > 0) //collectable moves right
            {
                for (int i = 0; i<size.y; i++) //iterate over the whole height of the collectable
                {
                    if ((*iter)-> contains(QPointF(x() +  (size.x-1)  + (speed.x - 1) - (*iter)->x() , y() + i -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            } //END OF FIRST CASE
        }
        return false;
    }

bool Collectable::collision_left()
{
    QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
    if (speed.x < 0) //collectable goes backwards
    {
        for (int i =0; i< size.y; i++)
        { //collision of the left of the collectable
            if ((*iter)-> contains(QPointF(x()  + speed.x   - (*iter)->x() , y() + i  -(*iter)->y() )))
            {
                return true;
            }
        }
    } //end of case 2
    }
    return false;
}

bool Collectable::collision_up()
{ // return if the up of the collectable suffers a collision with the player
    QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if (speed.y < 0) //collectable goes up
        {
            for (int i =0; i< size.x; i++)
            { //collision of the top of the collectable
                if ((*iter)-> contains(QPointF(x()  + i  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Collectable::collision_down()
{ // return if the down of the collectable suffers a collision with the player
    QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if(speed.y > 0) //collectable goes down
        {
            for (int i =0; i< size.x; i++)
            { //collision of the bottom of the projectile
                if ((*iter)-> contains(QPointF(x()  + i  - (*iter)->x() , y() + (size.y-1) + (speed.y-1) -(*iter)->y() )))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Collectable::move()
{
    QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
    for(int i = 0; i < colliding_items.size();i++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            QObject::deleteLater();
        }
    }

    if (collision_right() == true || collision_up() == true || collision_down() == true || collision_left() == true)
    {
        QObject::deleteLater();
    }
}

