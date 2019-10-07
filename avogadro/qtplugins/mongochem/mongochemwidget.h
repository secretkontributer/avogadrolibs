/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2019 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_QTPLUGINS_MONGOCHEMWIDGET_H
#define AVOGADRO_QTPLUGINS_MONGOCHEMWIDGET_H

#include <QScopedPointer>
#include <QWidget>

namespace Ui {
class MongoChemWidget;
}

class QNetworkAccessManager;
class QNetworkReply;

namespace Avogadro {

namespace QtPlugins {

class ConfigDialog;
class ListMoleculesModel;
class MongoChem;

class MongoChemWidget : public QWidget
{
  Q_OBJECT

public:
  explicit MongoChemWidget(MongoChem* plugin, QWidget* parent = nullptr);
  ~MongoChemWidget() override;

private slots:
  void showConfig();
  void finishAuthentication(const QVariantMap& results);
  void search();
  void finishSearch(const QVariantMap& results);
  void downloadSelectedMolecule();
  void finishDownloadMolecule(const QVariantMap& results);
  void uploadMolecule();
  void finishUploadMolecule(const QVariantMap& results);
  void error(const QString& message, QNetworkReply* reply);

private:
  void setupConnections();
  void authenticate();
  int selectedRow();

  MongoChem* m_plugin;

  QString m_girderUrl = "http://localhost:8080/api/v1";
  QString m_apiKey;
  QString m_girderToken;

  QScopedPointer<Ui::MongoChemWidget> m_ui;
  QScopedPointer<QNetworkAccessManager> m_networkManager;
  QScopedPointer<ConfigDialog> m_configDialog;
  QScopedPointer<ListMoleculesModel> m_listMoleculesModel;
};

} // namespace QtPlugins
} // namespace Avogadro

#endif // AVOGADRO_QTPLUGINS_MONGOCHEMWIDGET_H
