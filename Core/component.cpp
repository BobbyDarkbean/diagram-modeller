#include "private/component_si.h"
#include "component.h"


namespace DiagramModeller {


const int INVALID_COMPONENT_ID = -1;


ComponentSharedImplementation::ComponentSharedImplementation()
    : QSharedData(),
      category(CC_DiagramRoot),
      id(INVALID_COMPONENT_ID),
      name(),
      visibility(VS_Public),
      parentId(INVALID_COMPONENT_ID),
      docText(),
      properties(),
      children(),
      relations()
{
}


ComponentSharedImplementation::ComponentSharedImplementation(const ComponentSharedImplementation &other)
    : QSharedData(other),
      category(other.category),
      id(other.id),
      name(other.name),
      visibility(other.visibility),
      parentId(other.parentId),
      docText(other.docText),
      properties(other.properties),
      children(other.children),
      relations(other.relations)
{
}


ComponentSharedImplementation::~ComponentSharedImplementation()
{
}


Component::Component()
    : m(new ComponentSharedImplementation)
{
}


Component::Component(const Component &other)
    : m(other.m)
{
}


Component::~Component()
{
}


ComponentCategory Component::category() const { return m->category; }
void Component::setCategory(ComponentCategory value) { m->category = value; }

int Component::id() const { return m->id; }

QString Component::name() const { return m->name; }
void Component::setName(const QString & value) { m->name = value; }

VisibilityScope Component::visibility() const { return m->visibility; }
void Component::setVisibility(VisibilityScope value) { m->visibility = value; }

int Component::parentId() const { return m->parentId; }
void Component::setParentId(int value) { m->parentId = value; }

QString Component::docText() const { return m->docText; }
void Component::setDocText(const QString & value) { m->docText = value; }


bool Component::isValid() const { return m->id != INVALID_COMPONENT_ID; }

QVariant Component::property(const QString &key) const { return m->properties.value(key, QVariant()); }
bool Component::hasProperty(const QString &key) const { return m->properties.contains(key); }
void Component::setProperty(const QString &key, const QVariant &value) { m->properties.insert(key, value); }
bool Component::clearProperty(const QString &key) { return m->properties.remove(key) > 0; }
void Component::clearProperties() { m->properties.clear(); }

int Component::childrenCount() const { return 0; }
int Component::childAt(int i) { return -1; }
int Component::childIndex(int id) const { return -1; }
bool Component::hasChild(int id) const { return false; }
bool Component::insertChild(int i, int id) { return false; }
bool Component::removeChild(int id) { return false; }
bool Component::removeChildAt(int i) { return false; }
bool Component::moveChild(int from, int to) { return false; }
int Component::relationsCount() const { return -1; }
bool Component::hasRelation(int id) const { return false; }
bool Component::appendRelaion(int id) { return false; }
bool Component::removeRelation(int id) { return false; }


Component &Component::operator =(const Component &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
