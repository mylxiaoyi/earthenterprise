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


#include <sys/prctl.h>
#include <sys/types.h>
#include <unistd.h>

#include <QtWidgets/qapplication.h>
#include <QtGui/qpainter.h>
#include <QtWidgets/qstylefactory.h>
#include <gstRegistry.h>
#include <QtCore/qtranslator.h>
#include <QtCore/qtextcodec.h>
//#include <qgl.h>
#include <QtWidgets/qwidget.h>
#include <QtGui/qimage.h>
#include <QtCore/qfile.h>
#include <QtCore/qeventloop.h>
#include <QtWidgets/QSplashScreen>

#include <builddate.h>
#include "fusion/fusionversion.h"
#include "fusion/fusionui/MainWindow.h"
#include "fusion/fusionui/GlobalFusion.h"
#include "fusion/fusionui/Preferences.h"
#include "fusion/fusionui/SystemListener.h"
#include "fusion/autoingest/khVolumeManager.h"
#include "fusion/autoingest/MiscConfig.h"
#include "fusion/fusionui/GfxView.h"
#include "common/geFilePool.h"
#include "common/geInstallPaths.h"
#include "common/khFileUtils.h"
#include "common/khGetopt.h"

#include <iostream>

// -----------------------------------------------------------------------------

int main(int argc, char** argv) {
  int argn;
  FusionProductType type = GetFusionProductType();
  khGetopt options;
  options.choiceOpt("mode", type,
                    makemap(std::string("LT"),       FusionLT,
                            std::string("Pro"),      FusionPro,
                            std::string("Internal"), FusionInternal));
  if (!options.processAll(argc, argv, argn)) {
    notify(NFY_FATAL, "Error processing commandline options");
  }
  SetFusionProductType(type);


  //
  // must always create QApplication before initializing gst library
  //
  QApplication a(argc, argv);

  //
  // confirm opengl support
  //
  if (!QGLFormat::hasOpenGL()) {
    qWarning("This system has no OpenGL support.  Exiting.");
    return EXIT_FAILURE;
  }

  //
  // Pre-initialize the volume manager so it will find any problems
  // before we really do any work
  //
  theVolumeManager.Init();

  // Turn off any site-configured delay before accessing small files.
  // This just causes the GUI to look like it's hung. If the file really
  // isn't written yet, the low level routines will report an arror that
  // the GUI will report. The user can then retry it later.
  MiscConfig::Instance().NFSVisibilityDelay = 0;

  //
  // display splash screen
  //
  QString pixname("fusion_splash.png");
  if (!QFile::exists(pixname)) {
    pixname = QString::fromStdString(khComposePath(kGESharePath, pixname.toStdString()));
    std::cout << "pixname = " << pixname.toStdString();
    if (!QFile::exists(pixname))
      pixname = QString("");
  }

  QSplashScreen* splash = NULL;
  if (!pixname.isEmpty()) {
    QPixmap pixmap(pixname);
    splash = new QSplashScreen(pixmap);
    a.processEvents();
  }

  splash->show();
  return a.exec();

  //
  // initialize the gst library
  //
  /*geFilePool file_pool;
  gstInit(&file_pool);

  //
  // initialize all fusion globals
  //
  Preferences::init();
  GlobalFusion::init();

  //
  // qglwidget defaults to no alpha channel, turn this on
  //
  QGLFormat f;
  f.setAlpha(true);
  QGLFormat::setDefaultFormat(f);

  //
  // install translator
  //
  QTranslator translator(0);
  if (translator.load(QString("fusion_") + QTextCodec::locale(), ".")) {
    a.installTranslator(&translator);
  } else if (translator.load(QString("fusion_") + QTextCodec::locale(),
                             kGESharePath)) {
    a.installTranslator(&translator);
  }

  //
  // configure qt style
  //
  a.setStyle(QStyleFactory::create("platinum"));

  try {
    //
    // launch the system listener
    //
    SystemListener listener;
    AssetWatcherManager watcherManager;

    //
    // launch gui now
    //
    MainWindow* w = new MainWindow();

    // check if system has valid GL context.
    if (!w->gfxview->isValid()) {
      if (splash) {
        splash->finish(w);
        delete splash;
      }
      delete w;

      qWarning("Sorry, this system doesn't have sufficient OpenGL resources.");
      qWarning("Try setting LIBGL_ALWAYS_INDIRECT=yes in your environment.");
      return EXIT_FAILURE;
    }

    // initialize main window.
    w->Init();

    // first event is really slow for some unknown reason
    // so process it now before taking the splash screen away
    a.eventLoop()->processEvents(QEventLoop::ExcludeUserInput, 10);

    w->show();

    if (splash) {
      splash->finish(w);
      delete splash;
    }

    //a.connect(&a, SIGNAL(lastWindowClosed()), w, SLOT(fileExit()));

    //a.setMainWidget(w);

    int status = a.exec();

    //delete w;

    return status;
  } catch(const std::exception& e) {
    notify(NFY_FATAL, "Caught exception: %s", e.what());
  } catch(...) {
    notify(NFY_FATAL, "Caught unknown exception");
  }*/
  return 1;
}
