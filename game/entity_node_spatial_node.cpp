// Copyright (C) 2020-2024 Sami Väisänen
// Copyright (C) 2020-2024 Ensisoft http://www.ensisoft.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "game/entity_node_spatial_node.h"

#include "base/hash.h"
#include "data/writer.h"
#include "data/reader.h"

namespace game
{
SpatialNodeClass::SpatialNodeClass()
{
    mFlags.set(Flags::Enabled, true);
}
std::size_t SpatialNodeClass::GetHash() const
{
    size_t hash = 0;
    hash = base::hash_combine(hash, mShape);
    hash = base::hash_combine(hash, mFlags);
    return hash;
}
void SpatialNodeClass::IntoJson(data::Writer& data) const
{
    data.Write("shape", mShape);
    data.Write("flags", mFlags);
}

bool SpatialNodeClass::FromJson(const data::Reader& data)
{
    bool ok = true;
    ok &= data.Read("shape", &mShape);
    ok &= data.Read("flags", &mFlags);
    return ok;
}

} // namespace