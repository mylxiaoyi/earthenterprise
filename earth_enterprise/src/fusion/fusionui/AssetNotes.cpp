// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <QtWidgets/qtextedit.h>
#include <QtCore/qdatetime.h>

#include "AssetNotes.h"

AssetNotes::AssetNotes(QWidget* parent, const QString& text)
  : QDialog(parent), ui(new Ui::AssetNotesBase) {
  ui->setupUi(this);
  this->ui->notes_edit->setText(text);
  this->ui->notes_edit->setFocus();
  //this->ui->notes_edit->setCursorPosition(0, 0);
}

QString AssetNotes::GetText() const {
  return this->ui->notes_edit->toPlainText();
}

void AssetNotes::Timestamp() {
  QDateTime now = QDateTime::currentDateTime();
  this->ui->notes_edit->insertPlainText(now.toString("yyyy-MM-dd hh:mm"));
}
