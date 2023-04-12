/***********************************************************************************************************************
**
** Copyright (C) 2021 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#ifndef GPUI_TEMPLATEFILTERMODEL_H
#define GPUI_TEMPLATEFILTERMODEL_H

#include "../plugins/administrative_templates/registry/policystatemanager.h"
#include "gui.h"

#include <QSortFilterProxyModel>

namespace model
{
namespace registry
{
class AbstractRegistrySource;
}
} // namespace model

namespace gpui
{
class TemplateFilterModelPrivate;
class TemplateFilter;

/*!
 * \class TemplateFilterModel
 * \brief The TemplateFilterModel class
 *
 * \ingroup gpui
 */
class GPUI_GUI_EXPORT TemplateFilterModel final : public QSortFilterProxyModel
{
public:
    TemplateFilterModel(QObject *parent);
    ~TemplateFilterModel();

    void setFilter(const TemplateFilter &filter, const bool enabled);

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    bool filterAcceptsRow(const QModelIndex &index, const model::registry::PolicyStateManager::PolicyState state) const;

private:
    TemplateFilterModel(const TemplateFilterModel &) = delete;            // copy ctor
    TemplateFilterModel(TemplateFilterModel &&)      = delete;            // move ctor
    TemplateFilterModel &operator=(const TemplateFilterModel &) = delete; // copy assignment
    TemplateFilterModel &operator=(TemplateFilterModel &&) = delete;      // move assignment

private:
    TemplateFilterModelPrivate *d;
};

} // namespace gpui

#endif // GPUI_TEMPLATEFILTERMODEL_H
