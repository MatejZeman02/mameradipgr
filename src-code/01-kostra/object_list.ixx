export module object_list;

// import std.vector;
import std;

// Forward declaration of ObjectInstance to define ObjectList
export class ObjectInstance;
export using ObjectList = std::vector<ObjectInstance *>;
