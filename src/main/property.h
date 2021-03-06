/******************************************************************************
 * Copyright © 2014-2017 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#ifndef MARKETMAKER_CLI_PROPERTY_H
#define MARKETMAKER_CLI_PROPERTY_H

#include "basic.h"
#include "file.h"

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char *key;
    const char *value;
} Property;

typedef struct {
    size_t   size;
    size_t   capacity;
    Property *properties;
} PropertyGroup;

PropertyGroup *alloc_properties(size_t newCapacity);

PropertyGroup *realloc_properties(PropertyGroup *group, size_t newCapacity);

PropertyGroup *add_property(PropertyGroup *group, const char *key, const char *value);

PropertyGroup *put_property(PropertyGroup *group, const char *key, const char *value);

PropertyGroup *put_all_properties(PropertyGroup *destGroup, const PropertyGroup *sourceGroup);

size_t longest_key_len(const PropertyGroup *group);

#define PARSE_OPT_IGNORE_INVALID_LINES  0x0001

PropertyGroup *parse_properties(const char *str, char separator, int options, err_t *errp);

PropertyGroup *load_properties(AbstractFile *absFile, const char *path, err_t *err);

bool save_properties(const PropertyGroup *group, AbstractFile *absFile, const char *path, err_t *err);

void sort_properties(const PropertyGroup *group);

const char *find_property(const PropertyGroup *group, const char *key);

const char *find_property_ignore_case(const PropertyGroup *group, const char *key);

#ifdef __cplusplus
};
#endif

#endif //MARKETMAKER_CLI_PROPERTY_H
