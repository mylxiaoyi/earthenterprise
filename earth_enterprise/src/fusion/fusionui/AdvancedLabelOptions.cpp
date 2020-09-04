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


#include "AdvancedLabelOptions.h"

#include <QtWidgets/qradiobutton.h>
#include <QtGui/qvalidator.h>
#include <QtWidgets/qlineedit.h>

#include "advancedlabeloptionsbase.h"

//AdvancedLabelOptions::AdvancedLabelOptions( QWidget* parent, int maxquad)
    //: QDialog( parent ), ui(new Ui::AdvancedLabelOptionsBase)
//{
  //ui->setupUi(this);

  /*this->ui->subsetText->setValidator( new QIntValidator( 1, 10000, this ) );

  //setMax( maxquad );

  if ( maxquad == 0 ) {
    this->ui->maxBtn->setChecked( true );
    this->ui->subsetBtn->setChecked( false );
  } else { 
    this->ui->maxBtn->setChecked( false );
    this->ui->subsetBtn->setChecked( true );
  }*/
//}


//void AdvancedLabelOptions::decimationChange( int id )
//{
  /*if ( id == 0 && !this->ui->subsetText->text().isEmpty() )
    setMax( 0 );
  else if ( id == 1 && this->ui->subsetText->text().isEmpty() )
    setMax( 100 );*/
//}

void AdvancedLabelOptions::setMax( int max )
{
  /*if ( max == 0 ) {
    this->ui->subsetText->setEnabled( false );
    this->ui->subsetText->clear();
  } else {
    this->ui->subsetText->setEnabled( true );
    this->ui->subsetText->setText( QString::number( max ) );
  }*/
}


int AdvancedLabelOptions::getMax() const
{
  return 0;//this->ui->subsetText->text().toInt();
}
