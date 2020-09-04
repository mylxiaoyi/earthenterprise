/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef KHSRC_FUSION_FUSIONUI_DATABASEWIDGET_H__
#define KHSRC_FUSION_FUSIONUI_DATABASEWIDGET_H__

#include <autoingest/.idl/storage/DatabaseConfig.h>
#include "databasewidgetbase.h"
#include "common/khRefCounter.h"
#include "AssetWidgetBase.h"

class AssetBase;

class DatabaseWidget : public Ui::DatabaseWidgetBase, public AssetWidgetBase {
 public:
  DatabaseWidget(QWidget* parent, AssetBase* base);

  void Prefill(const DatabaseEditRequest& request);
  void AssembleEditRequest(DatabaseEditRequest* request);

  // inherited from DatabaseWidgetBase
  virtual void ChooseVectorProject();
  virtual void ClearVectorProject();
  virtual void ChooseImageryProject();
  virtual void ClearImageryProject();
  virtual void ChooseTerrainProject();
  //virtual void ClearTerrainProject();

 private:
  static QString empty_text;
};

#endif  // !KHSRC_FUSION_FUSIONUI_DATABASEWIDGET_H__
