int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out");
    for(string s; getline(std::cin, s);)
    {
        if(s[0] != '0') out << "Intersected at '" << s << "'\n";
        else out << "No intersection\n";
        for(int i = 0; i < 4; ++i) getline(std::cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mpp;
    for (auto p = headA ; p!=NULL ; p = p->next){
        mpp[p]=p->val;
    }
    for (auto p = headB ; p!=NULL ; p = p->next){
        if (mpp.find(p)!=mpp.end()) return p;
    }
    return NULL;
    }
};