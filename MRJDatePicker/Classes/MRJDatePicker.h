//
//  MRJDatePicker.h
//  MRJDatePickerDeomo
//
//  Created by MRJ on 3/5/18.
//  Copyright © 2016 MRJ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSDate+MRJDatePicker.h"

typedef NS_ENUM(NSInteger,MRJDatePickerMode) {
    MRJDatePickerModeTime,    // Displays hour, minute, and optionally AM/PM designation depending on the locale setting (e.g. 6 | 53 | PM)
    MRJDatePickerModeDate,     // Displays month, day, and year depending on the locale setting (e.g. November | 15 | 2007)
    MRJDatePickerModeDateAndTime, // Displays date, hour, minute, and optionally AM/PM designation depending on the locale setting (e.g. Wed Nov 15 | 6 | 53 | PM)
    MRJDatePickerModeYearAndMonth // Displays Year, Month,  designation depending on the locale setting (e.g. November | 2007)
};

@class MRJDatePicker;

@protocol MRJDatePickerDelegate <NSObject>

@optional
- (void)datePicker:(MRJDatePicker *)datePicker dateDidChange:(NSDate *)date;
- (void)datePicker:(MRJDatePicker *)datePicker didCancel:(UIButton *)sender;
- (void)datePicker:(MRJDatePicker *)dataPicker didSelectedDate:(NSDate *)date;

@end

@interface MRJDatePicker : UIControl
/**
 *  Title on the top of MRJDatePicker
 */
@property (nonatomic, copy) NSString *title;

//@property (nonatomic, strong) NSDate *date;
/**
 *  specify min/max date range. default is nil. When min > max, the values are ignored.
 */
@property (nonatomic, strong) NSDate *minimumDate;

@property (nonatomic, strong) NSDate *maximumDate;
/**
 * default is MRJDatePickerModeDate. setting nil returns to default
 */
@property (nonatomic, assign) MRJDatePickerMode datePickerMode;
/**
 *  default is [NSLocale currentLocale]. setting nil returns to default
 */
@property(nonatomic,strong) NSLocale      *locale;
/**
 *  default is [NSCalendar currentCalendar]. setting nil returns to default
 */
@property(nonatomic,copy)   NSCalendar    *calendar;

/**
 *   default is nil. use current time zone or time zone from calendar
 */
@property(nonatomic,strong) NSTimeZone    *timeZone;

/**
 *  read only property, indicate in datepicker is open.
 */
@property(nonatomic,readonly) BOOL        isOpen;

@property (nonatomic, weak) id<MRJDatePickerDelegate> delegate;

- (instancetype)initWithSuperView:(UIView*)superView;

- (instancetype)initDatePickerMode:(MRJDatePickerMode)datePickerMode andAddToSuperView:(UIView *)superView;

- (instancetype)initDatePickerMode:(MRJDatePickerMode)datePickerMode minDate:(NSDate *)minimumDate maxMamDate:(NSDate *)maximumDate  andAddToSuperView:(UIView *)superView;

- (void)setDate:(NSDate *)date animated:(BOOL)animated;

- (void)setTintColor:(UIColor *)tintColor;

- (void)setHighlightColor:(UIColor *)highlightColor;

- (void)show;

- (void)dismiss;

@end
