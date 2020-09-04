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


#include <QtWidgets/qlabel.h>

#include <builddate.h>
#include <fusionversion.h>
#include "GfxView.h"

#include "AboutFusion.h"

/*AboutFusion::AboutFusion(QWidget* parent)
    : QDialog(parent), ui(new Ui::AboutFusionBase) {
  ui->setupUi(this);

  setWindowTitle(QString::fromStdString(GetFusionProductName()));

  this->ui->fusionNameLabel->setText(QString::fromStdString(GetFusionProductName()));
  this->ui->versionLabel->setText(QString("%1").arg(GEE_LONG_VERSION));

  this->ui->buildDateLabel->setText(QString("%1").arg(BUILD_DATE));

  this->ui->maxTextureLabel->setText(GfxView::MaxTexSize);

  this->ui->bitsPerCompLabel->setText(GfxView::BitsPerComp);
}*/
