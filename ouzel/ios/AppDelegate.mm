// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#import "AppDelegate.h"
#import "ViewController.h"
#include "Engine.h"

@interface AppDelegate ()
{
    ouzel::Engine* _engine;
}
@end

@implementation AppDelegate

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    _engine = new ouzel::Engine();
    
    _window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    _window.rootViewController = [[ViewController alloc] init];
    
    [_window makeKeyAndVisible];
    
    return YES;
}

-(void)applicationWillResignActive:(UIApplication *)application
{
    
}

-(void)applicationDidEnterBackground:(UIApplication *)application
{
    
}

-(void)applicationWillEnterForeground:(UIApplication *)application
{
    
}

-(void)applicationDidBecomeActive:(UIApplication *)application
{
    
}

-(void)applicationWillTerminate:(UIApplication *)application
{
    delete _engine;
}

-(void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
    //TODO: free resources
}

@end
