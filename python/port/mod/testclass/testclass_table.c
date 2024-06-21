#include "testclass.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_3(test_drange_obj, Test::drange);
STATIC MP_DEFINE_CONST_FUN_OBJ_4(test_fill_octogone_obj, Test::fill_octogone);

STATIC const mp_rom_map_elem_t testclass_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_test) },
    { MP_ROM_QSTR(MP_QSTR_drange), MP_ROM_PTR(&test_drange_obj) },
    { MP_ROM_QSTR(MP_QSTR_fill_octogone), MP_ROM_PTR(&test_fill_octogone_obj) },
    // Ajoutez d'autres méthodes ici
};

STATIC MP_DEFINE_CONST_DICT(testclass_module_globals, testclass_module_globals_table);

const mp_obj_module_t testclass_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&testclass_module_globals,
};
