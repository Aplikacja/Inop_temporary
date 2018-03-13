#ifndef C_FABRIC_RELATION_HPP
#define C_FABRIC_RELATION_HPP
class C_fabric_relation {
public:
	C_fabric_relation() {}
	C_relation_base* m_create_relation() { return new C_relation; }
	~C_fabric_relation() {}
};
#endif // !C_FABRIC_RELATION_HPP