#pragma once

#include "ZombieTable.h"
#include "ItemTable.h"

class DataTableManger : public Singleton<DataTableManger>
{
	friend class Singleton<DataTableManger>;

private:
	std::unordered_map<DataTable::Types, DataTable*> tableMap;
	//�� ��� ��δ��� ���� ���� ���� 3����
	//1. �迭 ������ �����ϴ�.
	//2. �����͸� ã�� ���� 0(1) �ð� ���⵵�� ���� ���̵��̴�
	//3. �����͸� �������� ��������. && �ߺ�Ű�� ������� �ʴ´�.(�Ǳ���)


public:
	void Init();
	void Release();

	template<typename T>
	T* GetDataTable(DataTable::Types type);

protected:
	DataTableManger() = default;
	virtual ~DataTableManger();
	DataTableManger(const DataTableManger& other) = delete;
	DataTableManger& operator=(const DataTableManger& other) = delete;
};

template<typename T>
inline T* DataTableManger::GetDataTable(DataTable::Types type)
{
	auto find = tableMap.find(type);

	if (find == tableMap.end())
		return nullptr;

	return dynamic_cast<T*>(find->second);
}

#define DATATABLE_MANEGER (DataTableManger::Instance())
#define STRING_TABLE (DataTableManger::Instance().GetDataTable<StringTable>(DataTable::Types::String))
#define ZOMBIE_TABLE (DataTableManger::Instance().GetDataTable<ZombieTable>(DataTable::Types::Zombie))
#define ITEM_TABLE (DataTableManger::Instance().GetDataTable<ItemTable>(DataTable::Types::Item))