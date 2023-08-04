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

#ifndef GPUI_SMB_AUTHENTICATOIN_DIALOG_H
#define GPUI_SMB_AUTHENTICATOIN_DIALOG_H

#include <QtWidgets>

namespace gpui
{
namespace smb
{
class AuthenticationDialogPrivate;

class AuthenticationDialog : public QDialog
{
    Q_OBJECT

public:
    AuthenticationDialog();
    ~AuthenticationDialog();

private:
    AuthenticationDialogPrivate *const d;

private:
    AuthenticationDialog(const AuthenticationDialog &) = delete;            // copy ctor
    AuthenticationDialog(AuthenticationDialog &&)      = delete;            // move ctor
    AuthenticationDialog &operator=(const AuthenticationDialog &) = delete; // copy assignment
    AuthenticationDialog &operator=(AuthenticationDialog &&) = delete;      // move assignment
};

} // namespace smb

} // namespace gpui

#endif // GPUI_SMB_AUTHENTICATOIN_DIALOG_H
