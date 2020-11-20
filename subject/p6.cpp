#include<iostream>
#include<vector>
#include<stack>

struct node {
  node() {
    parent = son = brother = nullptr;
  }
  std::string name;
  node* parent;
  node* son;
  node* brother;
};

class tree {
public:
  tree():root(new node()){}
  tree(node* r):root(r){}
  ~tree() { clear(this->root); }

  node* get_root()const { return this->root; }
  void init();
  void complete();
  void add();
  void change();
  void clear(node* r);
  void erase();
  void print(node* r);
  void new_print(node* r,int deep=0);

private:
  void insert(node* r, std::string str);
  node* find(node* r, std::string str);

private:
  node* root;
  std::vector<int> width;
};

void tree::new_print(node* r,int deep=0){
  if (r == this->root) {
    std::cout << r->name;
    this->width.push_back(r->name.size()/2+1);
    if (r->son) {
      for (int i : width) {
        while (i--)
          std::cout << " ";
        std::cout << "|";
      }
    }
  }
  else {

  }
  r = r->son;
  while (r) {

  }
}

void tree::print(node* r) {
  if (!r)
    return;
  std::cout << r->name << "  ";
  r = r->son;
  while (r) {
    print(r);
    r = r->brother;
  }
}

void tree::change(){
  std::cout << "������Ҫ�����������˵�Ŀǰ����:";
  std::string str,name;
  std::cin >> str;
  node* r = find(root, str);
  std::cout << "��������ĺ������:";
  std::cin >> name;
  r->name = name;
  std::cout << str << "�Ѹ���Ϊ" << name;
  std::cout << '\n'<<'\n';
}

void tree::erase() {
  std::cout << "������Ҫ��ɢ�ļ�ͥ���˵�������";
  std::string str;
  std::cin >> str;
  node* r = new node();
  r = this->find(root, str);
  node *p, *q;
  p = r->son;
  std::cout << "Ҫ��ɢ��ͥ������:" << str << '\n';
  std::cout << str << "�ĵ�һ��������:";
  while (p) {
    std::cout << p->name << "  ";
    q = p->brother;
    delete p;
    p = q;
  }
  r->son = nullptr;
  std::cout << '\n' << '\n';
}

void tree::add() {
  std::cout << "������Ҫ���Ӷ��ӣ���Ů�������˵�����:";
  std::string str;
  std::cin >> str;
  std::cout << "������" << str << "�����ӵĶ��ӣ���Ů����������:";
  std::string name;
  std::cin >> name;
  node* r = new node();
  r = find(root, str);
  this->insert(r, name);
  std::cout << str << "�ĵ�һ��������:";
  r = r->son;
  while (r) {
    std::cout << r->name << "  ";
    r = r->brother;
  }
  std::cout << '\n'<<'\n';
}

void tree::insert(node* r, std::string str) {
  if (!r)
    return;
  if (!r->son) {
    r->son = new node();
    r->son->name = str;
    r->son->parent = r;
  }
  else {
    r = r->son;
    while (r->brother)
      r = r->brother;
    r->brother = new node();
    r->brother->name = str;
  }
}

void tree::clear(node* r) {
  if (!r)
    return;
  node* q = r->son;
  delete r;
  while (q) {
    node* p = q->brother;
    clear(q);
    q = p;
  }
}

node* tree::find(node* r,std::string str) {
  node* ans = new node();
  ans = nullptr;
  if (!r)
    return ans;
  if (r->name == str)
    return r;
  else {
    node* q = r->son;
    while (q && !(ans = find(q, str)))
      q = q->brother;
  }
  return ans;
}

void tree::init() {
  std::cout << "���Ƚ���һ�����ף�" << '\n';
  std::cout << "���������ȵ�����:";
  std::string str;
  std::cin >> str;
  this->root->name = str;
  std::cout << "�˼��׵�������:" << str << '\n' << '\n';
}

void tree::complete() {
  std::cout << "������Ҫ������ͥ���˵�����:";
  std::string str;
  std::cin >> str;
  node* r = new node();
  r = this->find(this->root,str);
  int num = 0;
  std::vector<std::string> vec;
  std::cout << "������" << str << "�Ķ�Ů����:";
  std::cin >> num;
  std::cout << "����������" << str << "�Ķ�Ů������:";
  while (num--) {
    std::string name;
    std::cin >> name;
    vec.push_back(name);
  }
  for (int i = 0; i < vec.size(); i++) {
    this->insert(r, vec[i]);
  }
  std::cout << str << "�ĵ�һ��������:";
  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << "  ";
  std::cout << '\n'<<'\n';
}

void solve() {
  tree genealogy;
  genealogy.init();
  char ch;
  while (true) {
    std::cout << "��ѡ��Ҫִ�еĲ���:";
    std::cin >> ch;
    if (ch == 'E')
      break;
    switch (ch) {
    case 'A': {
      genealogy.complete();
      break;
    }
    case 'B': {
      genealogy.add();
      break;
    }
    case 'C': {
      genealogy.erase();
      break;
    }
    case 'D': {
      genealogy.change();
      break;
    }
    case'F': {
      genealogy.print(genealogy.get_root());
      std::cout << '\n' << '\n';
    }
    }
  }
}

int main() {
 // solve();
  int a = 1, b = 2;
  std::cout << (a ^ b) << (a & b);
}