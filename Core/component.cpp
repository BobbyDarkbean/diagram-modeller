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


Component::Component(int id)
    : m(new ComponentSharedImplementation)
{
    m->id = id;
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

int Component::childrenCount() const { return m->children.size(); }
int Component::childAt(int i) { return m->children.value(i, INVALID_COMPONENT_ID); }
int Component::childIndex(int id) const { return m->children.indexOf(id); }
bool Component::hasChild(int id) const { return m->children.contains(id); }

bool Component::insertChild(int i, int id)
{
    if (!((0 <= i) && (i <= m->children.size())))
        return false;
    m->children.insert(i, id);
    return true;
}

bool Component::removeChild(int id) { return m->children.removeAll(id) > 0; }

bool Component::removeChildAt(int i)
{
    if (!((0 <= i) && (i < m->children.size())))
        return false;
    m->children.removeAt(i);
    return true;
}

bool Component::moveChild(int from, int to)
{
    if (!((0 <= from) && (from < m->children.size()))
       || !((0 <= to) && (to < m->children.size())))
        return false;

    m->children.move(from, to);
    return true;
}

int Component::relationsCount() const { return m->relations.size(); }
bool Component::hasRelation(int id) const { return m->relations.contains(id); }

bool Component::appendRelaion(int id)
{
    if (m->relations.contains(id))
        return false;
    m->relations.insert(id);
    return true;
}

bool Component::removeRelation(int id) { return m->relations.remove(id); }


Component &Component::operator =(const Component &other)
{
    m = other.m;
    return *this;
}


} // namespace DiagramModeller
