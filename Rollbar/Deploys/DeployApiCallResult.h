//  Copyright © 2018 Rollbar. All rights reserved.

#import <Foundation/Foundation.h>
#import "DeploymentDetails.h"
#import "DataTransferObject.h"
#import "DeployApiCallOutcome.h"

#pragma mark - DeployApiCallResult

/// Models result of Deploy API call/request
@interface DeployApiCallResult : DataTransferObject

/// API call's outcome
@property (readonly) DeployApiCallOutcome outcome;

/// API call's result description
@property (readonly, copy) NSString *description;

/// Initialize this DTO instance with valid JSON NSDictionary seed
/// @param data valid JSON NSDictionary seed
- (instancetype)initWithDictionary:(NSDictionary *)data NS_UNAVAILABLE;

/// Initialize this DTO instance with valid JSON NSArray seed
/// @param data valid JSON NSArray seed
- (instancetype)initWithArray:(NSArray *)data NS_UNAVAILABLE;

/// Initialize empty DTO
- (instancetype)init NS_UNAVAILABLE;

/// Designated initializer
/// @param httpResponse HTTP response object
/// @param extraResponseData extra response info
/// @param error error (if any)
/// @param request corresponding HTTP request
- (instancetype)initWithResponse:(NSHTTPURLResponse*)httpResponse
               extraResponseData:(id)extraResponseData
                           error:(NSError*)error
                      forRequest:(NSURLRequest*)request
NS_DESIGNATED_INITIALIZER;

/// Convenience initializer
/// @param httpResponse HTTP response object
/// @param data extra response data
/// @param error error (if any)
/// @param request  corresponding HTTP request
- (instancetype)initWithResponse:(NSHTTPURLResponse*)httpResponse
                            data:(NSData*)data
                           error:(NSError*)error
                      forRequest:(NSURLRequest*)request;

@end

#pragma mark - DeploymentRegistrationResult

/// Models result of a deployment registration request
@interface DeploymentRegistrationResult : DeployApiCallResult

/// Deployment ID
@property (readonly, copy) NSString *deploymentId;

@end

#pragma mark - DeploymentDetailsResult

/// Models result of a deployment details request
@interface DeploymentDetailsResult : DeployApiCallResult

/// Deployment details object
@property (readonly, retain) DeploymentDetails *deployment;

@end

#pragma mark - DeploymentDetailsPageResult

/// Models result of a deployment details page request
@interface DeploymentDetailsPageResult : DeployApiCallResult

/// Deployment details objects
@property (readonly, retain) NSArray<DeploymentDetails *> *deployments;

/// Deployment details page number
@property (readonly) NSUInteger pageNumber;

@end
