extern "C" {
#include "testclass.h"
#include <py/runtime.h>
}

#include <escher/palette.h>
#include <kandinsky.h>
#include <ion.h>
#include "port.h"
#include <py/obj.h>


mp_obj_t Test::drange(mp_obj_t start, mp_obj_t end, mp_obj_t step) {
    // Implémentation de drange ici
    return mp_obj_new_str("Test",4);
}

mp_obj_t Test::fill_octogone(mp_obj_t center_x, mp_obj_t center_y, mp_obj_t radius, mp_obj_t color) {
    // Implémentation de fill_octogone ici
    return mp_const_none;
}


