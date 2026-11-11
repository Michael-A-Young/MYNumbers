/**
@file
	TypeRegistry.inl
@brief
	Stores and retrieves resources by registered identifier.
*/

namespace MY
{

template <typename Resource>
TypeRegistry<Resource>::TypeRegistry(uint32_t firstCustomID)
	: mResources()
	, mFirstCustomID(firstCustomID)
	, mNextCustomID(firstCustomID)
{
}

template <typename Resource>
uint32_t TypeRegistry<Resource>::Register(Resource& resource)
{
	FindNextCustomID();

	const uint32_t typeID = mNextCustomID;
	Register(resource, typeID);
	return typeID;
}

template <typename Resource>
bool TypeRegistry<Resource>::Register(Resource& resource, uint32_t typeID)
{
	if (typeID == 0)
	{
		return false;
	}

	const auto result = mResources.try_emplace(typeID, &resource);
	return result.second;
}

template <typename Resource>
const Resource* TypeRegistry<Resource>::Get(uint32_t typeID) const
{
	const Resource* output = nullptr;
	const auto it = mResources.find(typeID);

	if (it != mResources.end())
	{
		output = it->second;
	}

	return output;
}

template <typename Resource>
void TypeRegistry<Resource>::GetIDs(std::vector<uint32_t>& outIDs) const
{
	outIDs.clear();
	outIDs.reserve(mResources.size());

	for (const auto& entry : mResources)
	{
		outIDs.push_back(entry.first);
	}

	std::sort(outIDs.begin(), outIDs.end());
}

template <typename Resource>
size_t TypeRegistry<Resource>::Num() const
{
	return mResources.size();
}

template <typename Resource>
void TypeRegistry<Resource>::FindNextCustomID()
{
	uint32_t freeID = mFirstCustomID;

	while (mResources.contains(freeID))
	{
		++freeID;
	}

	mNextCustomID = freeID;
}

} // namespace MY
