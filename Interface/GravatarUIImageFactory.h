//
//  PWSGravatarFactory.h
//  github
//
//  Created by Magnus Ernstsson on 10/4/10.
//  Copyright 2010 Patchwork Solutions AB. All rights reserved.
//

#import "GravatarService.h"

@protocol GravatarServiceDelegate;

@interface GravatarUIImageFactory : NSObject <GravatarService> {
  NSString *email;
  NSString *gravatarid;
  id<GravatarServiceDelegate> delegate;
  NSMutableData *receivedData;
  NSURLConnection *connection;
  BOOL failSent;
  BOOL cancelling;
}

@property (copy) NSString *email;
@property (copy) NSString *gravatarid;
@property (retain) id<GravatarServiceDelegate> delegate;
@property (retain) NSMutableData *receivedData;
@property (retain) NSURLConnection *connection;
@property (assign) BOOL failSent;
@property (assign) BOOL cancelling;

+(GravatarUIImageFactory *)gravatarUIImageFactoryWithDelegate:
(id<GravatarServiceDelegate>)delegate;

-(void)requestUIImageByGravatarId:(NSString *)gravatarId size:(NSInteger)size;

-(void)requestUIImageByGravatarId:(NSString *)gravatarId;

-(void)requestUIImageByEmail:(NSString *)gravatarId size:(NSInteger)size;

-(void)requestUIImageByEmail:(NSString *)gravatarId;

@end
