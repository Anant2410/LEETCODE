class LFUCache {
  unsigned int size;
  int minFrequency;
  struct Node{ 
      int value; 
      int frequency; 
      list<int>::iterator iter;
  };
  // key , { value , frequency , pointer to the frequency in the list}
  unordered_map<int, Node> M;

  // frequency , list of keys
  unordered_map<int, list<int> > FM;


public:
    LFUCache(int capacity) {
      size = capacity;
    }
    
    int get(int key) {

      if(!M.count(key))
        return -1;

      // remove old mappings
      // delete it from the list and MIter
      FM[ M[key].frequency].erase(M[key].iter);

      M[key].frequency+=1;
      FM[ M[key].frequency].push_back(key);
      M[key].iter = prev(FM[ M[key].frequency].end());


      if(!FM[minFrequency].size() ) 
        minFrequency++;

      return M[key].value;
    }
    
    void put(int key, int value) {

      if(size <= 0)
        return;

	  // if key is already present then update the value only
      int currentKeyValue = get(key);
      if(currentKeyValue != -1){
        M[key].value = value;
        return;
      }

	  // if our map if full remove the least Frequently used key
	  // delete from begining to remove the leat recently used key 
      if(M.size() >= size){
        M.erase(FM[minFrequency].front());
        FM[minFrequency].pop_front();
      }

      // insert into list with freq = 1 , add all the relevant values to M
      FM[1].push_back(key);
      M[key] = { value , 1 ,  prev(FM[1].end()) };
      minFrequency = 1;
    }
};