/*
 *
 * Copyright (c) 2011-2016 The University of Waikato, Hamilton, New Zealand.
 * All rights reserved.
 *
 * This file is part of libprotoident.
 *
 * This code has been developed by the University of Waikato WAND
 * research group. For further information please see http://www.wand.net.nz/
 *
 * libprotoident is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * libprotoident is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#include <string.h>

#include "libprotoident.h"
#include "proto_manager.h"
#include "proto_common.h"

static inline bool match_lc_magic(uint32_t payload) {
        if (MATCH(payload, 0xfb, 0xc0, 0xb6, 0xdb))
                return true;
        return false;
}

static inline bool match_litecoin(lpi_data_t *data, lpi_module_t *mod UNUSED) {

        /* Port 9333 */

        if (match_lc_magic(data->payload[0]) && match_lc_magic(data->payload[1]))
                return true;

	return false;
}

static lpi_module_t lpi_litecoin = {
	LPI_PROTO_LITECOIN,
	LPI_CATEGORY_ECOMMERCE,
	"Litecoin",
	5,
	match_litecoin
};

void register_litecoin(LPIModuleMap *mod_map) {
	register_protocol(&lpi_litecoin, mod_map);
}

