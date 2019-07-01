struct Edge
{
  int weight;
  Node* from;
  Node* to;
  Edge(int w, Node* f, Node* t)
    : weight(w), form(f), to(t)
  {}
};
