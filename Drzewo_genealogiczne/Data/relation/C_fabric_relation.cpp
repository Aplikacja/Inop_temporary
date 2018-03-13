#include "C_fabric_relation.hpp"

C_fabric_relation::C_fabric_relation() {}
C_relation_base* C_fabric_relation::m_create_relation() { return new C_relation; }
C_fabric_relation::~C_fabric_relation() {}