//
// Copyright 2011 Jeff Verkoeyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

@class NIStylesheet;

/**
 * A leight-weight DOM-like object with which you can attach views and stylesheets.
 *
 * This is not a full HTML DOM, to be clear, but its intent is the same. NIDOM is designed
 * to simplify the view <=> stylesheet relationship. Add a view to the DOM and it will
 * automatically apply any applicable styles from the attached stylesheet.
 */
@interface NIDOM : NSObject {
@private
  NIStylesheet* _stylesheet;
  NSMutableSet* _registeredViews;
  NSMutableDictionary* _viewToSelectorsMap;
}

// Designated initializer.

- (id)initWithStylesheet:(NIStylesheet *)stylesheet;

+ (id)domWithStylesheet:(NIStylesheet *)stylesheet;
+ (id)domWithStylesheetWithPathPrefix:(NSString *)pathPrefix paths:(NSString *)path, ...;

- (void)registerView:(UIView *)view;
- (void)registerView:(UIView *)view withCSSClass:(NSString *)cssClass;
- (void)unregisterView:(UIView *)view;
- (void)unregisterAllViews;
- (void)refresh;

@end

/**
 * Initializes a newly allocated DOM with the given stylesheet.
 *
 *      @fn NIDOM::initWithStylesheet:
 */

/**
 * Returns an autoreleased DOM initialized with the given stylesheet.
 *
 *      @fn NIDOM::domWithStylesheet:
 */

/**
 * Returns an autoreleased DOM initialized with a nil-terminated list of file paths.
 *
 *      @fn NIDOM::domWithStylesheetWithPathPrefix:paths:
 */

/**
 * Registers the given view with the DOM.
 *
 * The view's class will be used as the CSS selector when applying styles from the stylesheet.
 *
 *      @fn NIDOM::registerView:
 */

/**
 * Registers the given view with the DOM.
 *
 * The view's class as well as the given CSS class string will be used as the CSS selectors
 * when applying styles from the stylesheet.
 *
 *      @fn NIDOM::registerView:withCSSClass:
 */
