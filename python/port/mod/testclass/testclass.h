#ifndef TEST_H
#define TEST_H

#include <py/obj.h>

class Test {
    public:
        static mp_obj_t drange(mp_obj_t start, mp_obj_t end, mp_obj_t step);
        static mp_obj_t fill_octogone(mp_obj_t center_x, mp_obj_t center_y, mp_obj_t radius, mp_obj_t color);
        // Ajoutez d'autres méthodes ici
};

#endif // TEST_H
