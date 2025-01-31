// Copyright (c) 2022 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at https://mozilla.org/MPL/2.0/.
import * as React from 'react'
import * as S from './style'
import { withKnobs } from '@storybook/addon-knobs'

import './locale'
import MainPanel from '../components/main-panel'
import ThemeProvider from '$web-common/BraveCoreThemeProvider'
import { ContentStyle, FontFamily, FontSize, SiteSettings, Theme } from '../api/browser'

export default {
  title: 'Speedreader/Panels',
  parameters: {
    layout: 'centered'
  },
  argTypes: {
    locked: { control: { type: 'boolean', lock: false } }
  },
  decorators: [
    (Story: any) => {
      return (
        <ThemeProvider>
          <Story />
        </ThemeProvider>
      )
    },
    withKnobs
  ]
}

export const _Main = () => {
  const siteSettings: SiteSettings = {
    isEnabled: true,
    fontFamily: FontFamily.kSans,
    contentStyle: ContentStyle.kDefault,
    fontSize: FontSize.k100,
    theme: Theme.kDark,
    host: 'www.nytimes.com'
  }

  return (
    <S.PanelFrame>
      <MainPanel
        siteSettings={siteSettings}
        onThemeChange={() => {}}
        onFontSizeChange={() => {}}
        onContentStyleChange={() => {}}
        onFontFamilyChange={() => {}}
        onToggleChange={() => {}}
      />
    </S.PanelFrame>
  )
}
