package org.whut.mc.server.core.communication;

/**
 * Created by yangyang on 16-1-26.
 */
public interface Resolver {
    Response resolve(byte[] data);
}
