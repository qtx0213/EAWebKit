/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

/*
* This file was modified by Electronic Arts Inc Copyright � 2009
*/

#include "config.h"

#include "JSMimeType.h"

#include <wtf/GetPtr.h>

#include "JSPlugin.h"
#include "KURL.h"
#include "MimeType.h"
#include "Plugin.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSMimeTypeTableValues[5] =
{
    { "type", (intptr_t)JSMimeType::TypeAttrNum, DontDelete|ReadOnly, 0 },
    { "suffixes", (intptr_t)JSMimeType::SuffixesAttrNum, DontDelete|ReadOnly, 0 },
    { "description", (intptr_t)JSMimeType::DescriptionAttrNum, DontDelete|ReadOnly, 0 },
    { "enabledPlugin", (intptr_t)JSMimeType::EnabledPluginAttrNum, DontDelete|ReadOnly, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSMimeTypeTable = { 7, JSMimeTypeTableValues, 0 };

/* Hash table for prototype */

static const HashTableValue JSMimeTypePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSMimeTypePrototypeTable = { 0, JSMimeTypePrototypeTableValues, 0 };

const ClassInfo JSMimeTypePrototype::s_info = { "MimeTypePrototype", 0, &JSMimeTypePrototypeTable, 0 };

JSObject* JSMimeTypePrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSMimeType.prototype]]");
    return KJS::cacheGlobalObject<JSMimeTypePrototype>(exec, prototypeIdentifier);
}

const ClassInfo JSMimeType::s_info = { "MimeType", 0, &JSMimeTypeTable , 0 };

JSMimeType::JSMimeType(JSObject* prototype, MimeType* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSMimeType::~JSMimeType()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

bool JSMimeType::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSMimeType, Base>(exec, &JSMimeTypeTable, this, propertyName, slot);
}

JSValue* JSMimeType::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case TypeAttrNum: {
        MimeType* imp = static_cast<MimeType*>(impl());
        return jsString(exec, imp->type());
    }
    case SuffixesAttrNum: {
        MimeType* imp = static_cast<MimeType*>(impl());
        return jsString(exec, imp->suffixes());
    }
    case DescriptionAttrNum: {
        MimeType* imp = static_cast<MimeType*>(impl());
        return jsString(exec, imp->description());
    }
    case EnabledPluginAttrNum: {
        MimeType* imp = static_cast<MimeType*>(impl());
        return toJS(exec, WTF::getPtr(imp->enabledPlugin()));
    }
    }
    return 0;
}

KJS::JSValue* toJS(KJS::ExecState* exec, MimeType* obj)
{
    return cacheDOMObject<MimeType, JSMimeType, JSMimeTypePrototype>(exec, obj);
}
MimeType* toMimeType(KJS::JSValue* val)
{
    return val->isObject(&JSMimeType::s_info) ? static_cast<JSMimeType*>(val)->impl() : 0;
}

}
