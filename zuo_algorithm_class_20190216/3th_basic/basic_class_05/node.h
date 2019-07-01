template<typename T>
struct Node
{
  T val
  int in;
  int out;
  vector<Node*> nexts;
  vector<Edge*> edges;
};
