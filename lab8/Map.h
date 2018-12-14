#ifndef MAP_H_
#define MAP_H_

#include "Pair.h"
#include "Set18.h"    // must have insert that returns iterator!!!

using namespace std;

template<typename K, typename V>
class Map
{

private:

    Set<Pair<K, V>> themap;

public:
    Map() {}

    void printMap() const
    {
        typename Set<Pair<K, V>>::iterator itr;
        for (itr = themap.begin(); itr != themap.end(); ++itr)
        {
            cout << (*itr).first << ":" << (*itr).second << endl;
        }
        return;
    }

    V & operator[](K index)
    {   
        typename Set<Pair<K, V>>::iterator here;
        Pair<K, V> probe(index, V());
        here = themap.insert(probe);
        return (*here).second;
    }

    void remove(K & key)
    {
        Pair<K, V> probe;
        probe.first = key;
        themap.remove(probe);
        return;
    }

};

#endif
