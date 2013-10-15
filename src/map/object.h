/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file map/object.h Map tile accessors for object tiles. */

#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

#include "../stdafx.h"
#include "../tile/common.h"
#include "../tile/object.h"
#include "map.h"
#include "class.h"
#include "coord.h"
#include "../company_type.h"
#include "../object_type.h"

/**
 * Gets the ObjectType of the given object tile
 * @param t the tile to get the type from.
 * @pre IsObjectTile(t)
 * @return the type.
 */
static inline ObjectType GetObjectType(TileIndex t)
{
	return tile_get_object_type(&_mc[t]);
}

/**
 * Get the index of which object this tile is attached to.
 * @param t the tile
 * @pre IsObjectTile(t)
 * @return The ObjectID of the object.
 */
static inline ObjectID GetObjectIndex(TileIndex t)
{
	return tile_get_object_index(&_mc[t]);
}

/**
 * Get the random bits of this tile.
 * @param t The tile to get the bits for.
 * @pre IsObjectTile(t)
 * @return The random bits.
 */
static inline byte GetObjectRandomBits(TileIndex t)
{
	assert(IsObjectTile(t));
	return tile_get_random_bits(&_mc[t]);
}


/**
 * Does the given tile have a transmitter?
 * @param t the tile to inspect.
 * @return true if and only if the tile has a transmitter.
 */
static inline bool IsTransmitterTile(TileIndex t)
{
	return tile_is_object(&_mc[t]) && tile_get_object_type(&_mc[t]) == OBJECT_TRANSMITTER;
}

/**
 * Is this object tile an 'owned land' tile?
 * @param t the tile to inspect.
 * @pre IsObjectTile(t)
 * @return true if and only if the tile is an 'owned land' tile.
 */
static inline bool IsOwnedLand(TileIndex t)
{
	return tile_get_object_type(&_mc[t]) == OBJECT_OWNED_LAND;
}

/**
 * Is the given tile (pre-)owned by someone (the little flags)?
 * @param t the tile to inspect.
 * @return true if and only if the tile is an 'owned land' tile.
 */
static inline bool IsOwnedLandTile(TileIndex t)
{
	return tile_is_object(&_mc[t]) && tile_get_object_type(&_mc[t]) == OBJECT_OWNED_LAND;
}

/**
 * Is this object tile a HQ tile?
 * @param t the tile to inspect.
 * @pre IsObjectTile(t)
 * @return true if and only if the tile is a HQ tile.
 */
static inline bool IsCompanyHQ(TileIndex t)
{
	return tile_get_object_type(&_mc[t]) == OBJECT_HQ;
}

/**
 * Is this object tile a statue?
 * @param t the tile to inspect.
 * @pre IsObjectTile(t)
 * @return true if and only if the tile is a statue.
 */
static inline bool IsStatue(TileIndex t)
{
	return tile_get_object_type(&_mc[t]) == OBJECT_STATUE;
}

/**
 * Is the given tile a statue?
 * @param t the tile to inspect.
 * @return true if and only if the tile is a statue.
 */
static inline bool IsStatueTile(TileIndex t)
{
	return tile_is_object(&_mc[t]) && tile_get_object_type(&_mc[t]) == OBJECT_STATUE;
}


/**
 * Make an Object tile.
 * @note do not use this function directly. Use one of the other Make* functions.
 * @param t      The tile to make and object tile.
 * @param u      The object type of the tile.
 * @param o      The new owner of the tile.
 * @param index  Index to the object.
 * @param wc     Water class for this object.
 * @param random Random data to store on the tile
 */
static inline void MakeObject(TileIndex t, ObjectType u, Owner o, ObjectID index, WaterClass wc, byte random)
{
	tile_make_object(&_mc[t], u, o, index, wc, random);
}

#endif /* MAP_OBJECT_H */
