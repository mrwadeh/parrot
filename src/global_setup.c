/* global_setup.c
 *  Copyright: (When this is determined...it will go here)
 *  CVS Info
 *     $Id$
 *  Overview:
 *      Performs all the global setting up of things. This includes the
 *      (very few) global variables that Parrot totes around
 *  Data Structure and Algorithms:
 *  History:
 *  Notes:
 *  References:
 */

#define INSIDE_GLOBAL_SETUP
#include "parrot/parrot.h"

void
init_world(void)
{
    KEY *key;
    string_init();              /* Set up the string subsystem */

    /* Call base vtable class constructor methods! */
    Parrot_Array_class_init(enum_class_Array);
    Parrot_PerlUndef_class_init(enum_class_PerlUndef);
    Parrot_PerlInt_class_init(enum_class_PerlInt);
    Parrot_PerlNum_class_init(enum_class_PerlNum);
    Parrot_PerlString_class_init(enum_class_PerlString);
    Parrot_PerlArray_class_init(enum_class_PerlArray);
    Parrot_PerlHash_class_init(enum_class_PerlHash);
    Parrot_ParrotPointer_class_init(enum_class_ParrotPointer);
    Parrot_IntQueue_class_init(enum_class_IntQueue);
    Parrot_ParrotSub_class_init(enum_class_ParrotSub);
    Parrot_ParrotCoroutine_class_init(enum_class_ParrotCoroutine);

    /* Now register the names of the PMCs */

    /* We need a key to work with */
    key = key_new(NULL);
    key->atom.type = enum_key_string;

    /* And we need a hash */
    Parrot_base_classname_hash = pmc_new(NULL, enum_class_PerlHash);
    Parrot_base_classname_hash->vtable->init(NULL, Parrot_base_classname_hash);

    /* Now start filling the hash */

    /* Array */
    key->atom.val.string_val =
        (STRING*)Parrot_base_vtables[enum_class_Array].name(NULL,
                                                            NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_Array);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_PerlUndef].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_PerlUndef);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_PerlInt].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_PerlInt);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_PerlNum].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_PerlNum);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_PerlString].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_PerlString);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_PerlArray].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_PerlArray);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_PerlHash].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_PerlHash);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_ParrotPointer].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_ParrotPointer);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_IntQueue].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_IntQueue);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_ParrotSub].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_ParrotSub);

    key->atom.val.string_val = (STRING*)
        Parrot_base_vtables[enum_class_ParrotCoroutine].name(NULL, NULL);
    key->atom.type = enum_key_string;
    Parrot_base_classname_hash->vtable->set_integer_keyed(NULL,
                                                          Parrot_base_classname_hash, key, enum_class_ParrotCoroutine);

}

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vim: expandtab shiftwidth=4:
*/
