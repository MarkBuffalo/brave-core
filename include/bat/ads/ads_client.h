/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include <string>
#include <memory>

#include "bat/ads/ad_info.h"
#include "bat/ads/bundle_category_info.h"
#include "bat/ads/bundle_state.h"
#include "bat/ads/callback_handler.h"
#include "bat/ads/client_info.h"
#include "bat/ads/export.h"
#include "bat/ads/url_components.h"
#include "bat/ads/url_session_callback_handler.h"
#include "bat/ads/url_session.h"

namespace ads {

enum ADS_EXPORT LogLevel {
  INFO,
  WARNING,
  ERROR
};

class ADS_EXPORT AdsClient {
 public:
  virtual ~AdsClient() = default;

  // Gets information about the client
  virtual void GetClientInfo(ClientInfo& client_info) const = 0;

  // Loads the user model
  virtual void LoadUserModel(CallbackHandler* callback_handler) = 0;

  // Set locale
  virtual std::string SetLocale(const std::string& locale) = 0;

  // Gets available locales
  virtual void GetLocales(std::vector<std::string>& locales) const = 0;

  // Generates an Ad UUID
  virtual void GenerateAdUUID(std::string& ad_uuid) const = 0;

  // Gets the network SSID or "Unknown" if not available
  virtual void GetSSID(std::string& ssid) const = 0;

  // Shows the specified ad
  virtual void ShowAd(const std::unique_ptr<AdInfo> info) = 0;

  // Creates a timer with the specified id and time-offset
  virtual void SetTimer(const uint64_t time_offset, uint32_t& timer_id) = 0;

  // Destroys the specified timer
  virtual void KillTimer(uint32_t& timer_id) = 0;

  // Starts a URL session task
  virtual std::unique_ptr<URLSession> URLSessionTask(
      const std::string& url,
      const std::vector<std::string>& headers,
      const std::string& content,
      const std::string& content_type,
      const URLSession::Method& method,
      URLSessionCallbackHandlerCallback callback) = 0;

  // Loads settings
  virtual void LoadSettings(CallbackHandler* callback_handler) = 0;

  // Saves the client
  virtual void SaveClient(
      const std::string& json,
      CallbackHandler* callback_handler) = 0;

  // Loads the client state
  virtual void LoadClient(CallbackHandler* callback_handler) = 0;

  // Serializes the catalog
  virtual void SaveCatalog(
      const std::string& json,
      CallbackHandler* callback_handler) = 0;

  // Loads the catalog
  virtual void LoadCatalog(CallbackHandler* callback_handler) = 0;

  // Resets the catalog
  virtual void ResetCatalog() = 0;

  // Saves the bundle
  virtual void SaveBundle(
      const BUNDLE_STATE& bundle_state,
      CallbackHandler* callback_handler) = 0;

  // Serializes the bundle
  virtual void SaveBundle(
      const std::string& json,
      CallbackHandler* callback_handler) = 0;

  // Loads the bundle
  virtual void LoadBundle(CallbackHandler* callback_handler) = 0;

  // Gets available ads based upon the winning category
  virtual void GetAds(
      const std::string& winning_category,
      CallbackHandler* callback_handler) = 0;

  // Gets a random sample category
  virtual void GetSampleCategory(CallbackHandler* callback_handler) = 0;

  // Gets the components of a URL
  virtual void GetUrlComponents(
      const std::string& url,
      UrlComponents& components) const = 0;

  // Log an event
  virtual void EventLog(const std::string& json) = 0;

  // Log debug information
  virtual void DebugLog(const LogLevel log_level, const char *fmt, ...) const = 0;
};

}  // namespace ads
