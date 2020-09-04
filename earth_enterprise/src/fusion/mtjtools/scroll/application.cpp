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


#include <QtGui/qimage.h>
#include <QtGui/qpixmap.h>
#include <QtWidgets/qtoolbar.h>
#include <QtWidgets/qtoolbutton.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qtextedit.h>
#include <QtCore/qfile.h>
#include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qstatusbar.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qapplication.h>
//#include <Qt3Support/q3accel.h>
#include <QtCore/qtextstream.h>
#include <QtGui/qpainter.h>
//#include <Qt3Support/q3paintdevicemetrics.h>
//#include <Qt3Support/q3simplerichtext.h>
//#include <Qt3Support/q3grid.h>
//#include <Qt3Support/q3mimefactory.h>

//#include <Qt3Support/q3canvas.h>

#include "fileopen.xpm"

#include "application.h"
#include "imageview.h"
#include <gdal/gdal.h>

#include <QtGui/QCloseEvent>

ApplicationWindow::ApplicationWindow()
    : QMainWindow( 0 )//, "scroll")//, WDestructiveClose | WGroupLeader )
{
  QPixmap openIcon;

  QToolBar * fileTools = new QToolBar( "file operations", this );
  fileTools->setWindowTitle( "File Operations" );

  openIcon = QPixmap( fileopen );
  //(void) new QToolButton( openIcon, "Open", QString::null,
  //                        this, SLOT(choose()), fileTools, "open" );

  //Q3MimeSourceFactory::defaultFactory()->setPixmap( "fileopen", openIcon );

  /*Q3PopupMenu * file = new Q3PopupMenu( this );
  //menuBar()->insertItem( "&File", file );
  menuBar()->addMenu("&File");

  //file->insertMenu( openIcon, "&Open...",
  //                       this, SLOT(choose()), CTRL+Qt::Key_O );
  file->addMenu("&Open");
  //file->insertMenu( "&Save", this, SLOT(save()));
  file->addMenu("&Save");

  file->addSeparator();

  //file->insertMenu( "&Quit", qApp, SLOT( closeAllWindows() ), Qt::ControlModifier+Qt::Key_Q );
  file->addMenu("&Quit");*/

  /*Q3PopupMenu * help = new Q3PopupMenu( this );
  //menuBar()->insertMenu( "&Help", help );
  menuBar()->addMenu(help);
  //help->insertMenu( "&Commands", this,
  //                  SLOT(keyhelps()), Qt::ControlModifier+Qt::Key_H);
  help->addMenu("&Commands");*/



  // setup GDAL once per execution
  GDALSetCacheMax(512*1024*1024);
  GDALAllRegister();

  viewer = new ImageView(this, "viewer");
  viewer->setStatusBar(statusBar());
  viewer->setFocus();

  setCentralWidget(viewer);
  statusBar()->showMessage( "Please open an image", 0 );

  resize(800, 600);
}

ApplicationWindow::~ApplicationWindow()
{
}

void ApplicationWindow::loadInitImage(const std::string &image_file_path) {
  QString abs_file_path;
  // Set prevDir per fileName (using non executed QFileDialog setting.)
  QFileDialog *fdlg = new QFileDialog(this);
  //fdlg->setSelection(image_file_path);
  setWindowTitle(fdlg->selectedFiles()[0]); // using selectedFile() to get full path
  //prevDir = fdlg->selectedUrls()[0];
  delete fdlg;
  viewer->loadInitImage(image_file_path);
}


void ApplicationWindow::choose()
{
  QFileDialog *fdlg = new QFileDialog(this, "", prevDir);
  //fdlg->setFilter("Images (*.pre *.img *.tif *.tiff *.jp2 *.sid *.jpg *.IMG *.TIF *.TIFF *.JP2 *.SID *.JPG)");
  if (fdlg->exec() == QDialog::Accepted) {
    //prevDir = fdlg->selectedUrls()[0];
    load(fdlg->selectedFiles()[0]);
  }
  delete fdlg;
}

void ApplicationWindow::save()
{
  viewer->SaveLutWork();
}

void ApplicationWindow::keyhelps()
{
  QMessageBox::about
    (this, "Command Help",
     "<table>"
     "<tr><td align='center' colspan='2'><b>Keyboard Commands</b></td></tr>"
     "<tr><td width='30%'>0 - 7</td><td width='70%'>set mouse radius</td></tr>"
     "<tr><td>up,down,left,right</td><td>move mouse</td></tr>"
     "<tr><td>pageup, pagedown, shift-up, shift-down, shift-left, shift-right, ctrl-shift-up, ctrl-shift-down, ctrl-shift-left, ctrl-shift-right</td><td>scroll image</td></tr>"
     "<tr><td>=</td><td>reset on file open</td></tr>"
     "<tr><td>-</td><td>toggle \"swap red and blue\" mode</td></tr>"
     "<tr><td>u, U</td><td>lower/increase row limit</td></tr>"
     "<tr><td>l, L</td><td>less/more left tail clip during histogram</td></tr>"
     "<tr><td>r, R</td><td>less/more right tail clip during histogram</td></tr>"
     "<tr><td>p, P</td><td>less/more pre-gamma</td></tr>"
     "<tr><td>g, G</td><td>less/more post-gamma</td></tr>"
     "<tr><td>z, Z</td><td>less/more zoom</td></tr>"
     "<tr><td>ALT-z, ALT-Z</td><td>less/more zoom (4 levels at a time)</td></tr>"
     "<tr><td>s, S</td><td>less/more contrast</td></tr>"
     "<tr><td>h</td><td>compute histogram</td></tr>"
     "<tr><td>c</td><td>toggle correct mode</td></tr>"
     "<tr><td>del, backspace</td><td>remove sample(s)</td></tr>"
     "<tr><td>Alt-w, Alt-W</td><td>write .lut file</td></tr>"
     "<tr><td>w, W</td><td>write .p,.lut, & .info files</td></tr>"
     "<tr><td>A</td><td>apply lut and write new image</td></tr>"
     "<tr><td>Home</td><td>Return to zoom & position right before last right mouse press</td></tr>"

     "<tr><td align='center' colspan='2'><b>Mouse Commands</b></td></tr>"
     "<tr><td>left mouse press</td><td>add sample(s)</td></tr>"
     "<tr><td>right mouse press</td><td>recenter and zoom just beyond fullres</td></tr>"

     "</table>"
     );
}

void ApplicationWindow::load( const QString &fileName )
{
  viewer->setFilename((char *)fileName.toLatin1().data());
  //setCaption(fileName);
  setWindowTitle(fileName);
}

void ApplicationWindow::closeEvent( QCloseEvent* ce )
{
  ce->accept();
}
