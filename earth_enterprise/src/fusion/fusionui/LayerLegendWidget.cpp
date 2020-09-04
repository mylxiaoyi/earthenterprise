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

//

#include "LayerLegendWidget.h"

#include <QtWidgets/qlayout.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qcheckbox.h>

class EndEditTable /*: public QTable*/ {
 public:
  //EndEditTable(QWidget* parent, const char* name) : QTable(parent, name) {}
  void EndEdit();
};

void EndEditTable::EndEdit() {
  /*if (isEditing()) {
    endEdit(currEditRow(), currEditCol(), true, true);
  }*/
}

LayerLegendWidget::LayerLegendWidget(QWidget* parent) :
    QWidget(parent)
{
  /*vlayout = new QVBoxLayout(this);
  vlayout->setAlignment(Qt::AlignTop);

  filter_check = new QCheckBox(this, "filter_check");
  filter_check->setChecked(true);
  vlayout->addWidget(filter_check);
  
  table = new EndEditTable(this, "legend_table");
  table->setSizePolicy(
      QSizePolicy(QSizePolicy::Expanding,
                  QSizePolicy::MinimumExpanding,
                  0, 0, 
                  false ));
  table->setNumRows(0);
  table->setNumCols(0);
  vlayout->addWidget(table);

  languageChange();*/
}


LayerLegendWidget::~LayerLegendWidget(void)
{
  // no need to delete children, Qt does it for us
}

void LayerLegendWidget::EndEdit() {
  //table->EndEdit();
}

/*QTable* LayerLegendWidget::GetTable() {
  return table;
}*/

void LayerLegendWidget::languageChange() {
  //filter_check->setText(tr("Hide unspecialized locales"));
}
